# Algorithms preparation (C++)

Daily algorithms and data structures practice in modern C++, used as preparation for technical interviews.

## Structure

- `algorithms/` one directory per topic (arrays, hashing, trees, graphs, dynamic programming, heaps, intervals)
- `notes/` study notes, one file per topic, plus the preparation plan
- `common/` small helpers shared by the solutions (test harness, timing utilities)

Each problem lives in its own file with:

- the problem statement as a comment at the top
- the first attempt, if it was not accepted, kept as a comment or in a separate `attempts/` file
- the final solution, rewritten from scratch after studying the reference

## Conventions

- C++17 minimum, C++20 when it helps readability
- Compiled with clang, warnings treated as errors
- Each solution has at least one test case covering edge cases (empty input, single element, duplicates)
- Complexity (time and space) stated in a comment next to the solution

## Build and run

Once the toolchain is set up:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build
```

## Status

Work in progress. See `notes/plan.md` for the weekly schedule.
