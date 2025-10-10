# ===== STAGE 1: BUILD =====
FROM alpine:3.20 AS builder

RUN apk add --no-cache g++ cmake make

WORKDIR /app
COPY . .

# Disable tests during Docker build
RUN mkdir build && cd build && cmake -DBUILD_TESTS=OFF .. && make

# ===== STAGE 2: RUNTIME =====
FROM alpine:3.20

RUN apk add --no-cache libstdc++ libgcc

WORKDIR /app
COPY --from=builder /app/build/calculator .

CMD ["./calculator"]
