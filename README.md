Small tangible experiments with performance.
Based on https://jvns.ca/blog/2014/05/12/computers-are-fast/

## Results

| Lan/Env        | Time      |
| -------------- |:---------:|
| py3/mac/n=1    | 51.47s    |
| py3/mac/n=2    | 51.58s    |
| gcc/mac/n=1    | 2.19s     |
| gcc/mac/n=2    | 2.20s     |
| rust/mac/n=1   | 2.20s     |
| rust/mac/n=2   | 2.25s     |
| py3/linux/n=1  | 69.32s    |
| py3/linux/n=2  | 68.22s    |
| gcc/linux/n=1  | 4.68s     |
| gcc/linux/n=2  | 3.94s     |
| rust/linux/n=1 | 4.93s     |
| rust/linux/n=2 | 3.75s     |

n - Nth time the test was run. The 2nd time we'd expect file is cached and
    should take less time.

mac - test was run on MacBook Pro: i7, 16 GB RAM, SSD
