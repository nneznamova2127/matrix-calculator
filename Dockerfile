# Multi-stage build for smaller final image
FROM ubuntu:22.04 AS builder

# Install build dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    cmake \
    g++ \
    git \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build the project
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make matrix_calculator

# Runtime stage
FROM ubuntu:22.04

# Install runtime dependencies if needed
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    # Add any runtime dependencies here if needed
    && rm -rf /var/lib/apt/lists/*

# Create non-root user for security
RUN groupadd -r appuser && useradd -r -g appuser appuser

WORKDIR /app

# Copy only the built binary from builder stage
COPY --from=builder /app/build/matrix_calculator .

# Change ownership to non-root user
RUN chown appuser:appuser matrix_calculator

# Switch to non-root user
USER appuser

# Set entrypoint
CMD ["./matrix_calculator"]
