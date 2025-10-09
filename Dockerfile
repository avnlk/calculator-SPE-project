# Base image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ cmake make libgtest-dev && rm -rf /var/lib/apt/lists/*

# Copy project
WORKDIR /app
COPY . /app

# Build calculator
RUN mkdir -p build && cd build && cmake .. && make

# Default command
CMD ["./build/calculator"]
