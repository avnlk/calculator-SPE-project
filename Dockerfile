# ===== STAGE 1: BUILD =====
FROM alpine:3.20 AS builder

# Install compiler and build tools
RUN apk add --no-cache g++ cmake make

# Copy calculator source
WORKDIR /app
COPY . .

# Build the calculator as a fully static binary
RUN mkdir build && cd build && cmake .. && \
    make calculator LDFLAGS="-static"

# ===== STAGE 2: RUNTIME =====
FROM scratch

WORKDIR /app

# Copy the fully static calculator binary
COPY --from=builder /app/build/calculator .

# Run the calculator
CMD ["./calculator"]
