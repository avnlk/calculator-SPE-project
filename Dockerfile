# =========================
# Stage 1: Build
# =========================
FROM gcc:11 AS builder

# Install required build tools and libraries
RUN apt-get update && \
    apt-get install -y cmake make libgtest-dev && \
    rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy all project files
COPY . .

# Build the calculator
RUN mkdir build && cd build && cmake .. && make

# =========================
# Stage 2: Runtime
# =========================
# Use a super lightweight base image
FROM debian:bullseye-slim

# Create app directory
WORKDIR /app

# Copy only the final executable (and any runtime dependencies)
COPY --from=builder /app/build/calculator ./calculator

# Install only minimal runtime dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
        libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Run the calculator app
CMD ["./calculator"]
