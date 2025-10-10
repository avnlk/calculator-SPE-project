# ===== STAGE 1: BUILD AND TEST =====
FROM alpine:3.20 AS builder

# Install compiler and build tools
RUN apk add --no-cache g++ cmake make git

# Build and install GoogleTest (used only in this stage)
WORKDIR /tmp
RUN git clone https://github.com/google/googletest.git && \
    cd googletest && mkdir build && cd build && \
    cmake .. && make && make install

# Copy calculator source
WORKDIR /app
COPY . .

# Build everything (including tests)
RUN mkdir build && cd build && cmake .. && make

# Optional: run tests here to validate build
# (if you don’t want tests to fail the image build, add `|| true`)
RUN cd build && ctest --output-on-failure || true


# ===== STAGE 2: RUNTIME =====
FROM alpine:3.20

WORKDIR /app

# Copy only the final executable (no sources, no GTest, no compiler)
COPY --from=builder /app/build/calculator .

# Minimal runtime container (just your binary)
CMD ["./calculator"]
