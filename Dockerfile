# ===== STAGE 1: BUILD =====
FROM alpine:3.20 AS builder

# Install only minimal tools to build
RUN apk add --no-cache g++ cmake make

WORKDIR /app

# Copy all project files
COPY . .

# Configure & compile
RUN mkdir build && cd build && cmake .. && make

# ===== STAGE 2: RUNTIME =====
FROM alpine:3.20

# Set work directory
WORKDIR /app

# Copy the compiled binary from builder stage
COPY --from=builder /app/build/calculator ./calculator

# Run calculator
CMD ["./calculator"]
