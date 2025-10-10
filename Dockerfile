# ===== STAGE 1: BUILD =====
FROM alpine:3.20 AS builder

# Install compiler and build tools
RUN apk add --no-cache g++ cmake make

# Copy calculator source
WORKDIR /app
COPY . .

# Build the calculator executable
RUN mkdir build && cd build && cmake .. && make

# ===== STAGE 2: RUNTIME =====
FROM alpine:3.20

WORKDIR /app

# Install minimal C++ runtime libraries
RUN apk add --no-cache libstdc++ libgcc

# Copy the built calculator binary
COPY --from=builder /app/build/calculator .

# Run the calculator
CMD ["./calculator"]
