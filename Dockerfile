# ===== STAGE 1: BUILD =====
FROM alpine:3.20 AS builder

# Install compiler and build tools
RUN apk add --no-cache g++ cmake make

# Copy calculator source code
WORKDIR /app
COPY . .

# Build calculator only
RUN mkdir build && cd build && cmake .. && make

# ===== STAGE 2: RUNTIME =====
FROM alpine:3.20

# Install C++ runtime libraries
RUN apk add --no-cache libstdc++ libgcc

WORKDIR /app

# Copy only the compiled binary
COPY --from=builder /app/build/calculator .

# Set default command
CMD ["./calculator"]
