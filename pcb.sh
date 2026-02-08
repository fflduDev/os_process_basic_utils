#! /bin/bash

PID=$1  

echo "=== Process State ==="
cat /proc/$PID/status | grep State

echo -e "\n=== Process Number ==="
echo "PID: $PID"

echo -e "\n=== Program Counter ==="
cat /proc/$PID/syscall 2>/dev/null || echo "Not available"

echo -e "\n=== Memory Limits ==="
cat /proc/$PID/limits | grep -E '(RESOURCE|mem|stack|data)'

echo -e "\n=== Open Files ==="
ls -l /proc/$PID/fd/ | head -10