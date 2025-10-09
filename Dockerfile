FROM ubuntu:22.04

# Install build tools
RUN apt-get update && \
    apt-get install -y g++ cmake make libgtest-dev && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy source files only
COPY . /app

# Build the project
RUN mkdir build && cd build && cmake .. && make

CMD ["./build/calculator"]
