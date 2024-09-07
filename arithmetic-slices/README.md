# Arithmetic Slices

Trick here is really simple.

Suppose we have our current slice:

``` python3
count = 0, curr = 0
[1, 2, 3]
count = 1, curr = 1
```

We then add `4` to this:

``` python3
count = 1, curr = 1
[1, 2, 3, 4]
count = 2, curr = 3
```

The reason this works is because we already used up `[1, 2, 3]`. Adding `4` gives `[1, 2, 3, 4]` and `[2, 3, 4]`. In general, adding 1 consecutive element gives `count` extra arrays if we have the valid array size.

To test this, add `5`

``` python3
count = 2, curr = 3
[1, 2, 3, 4, 5]
count = 3, curr = 6
```

The extra arrays are:

``` python3
[3, 4, 5], [2, 3, 4, 5], [1, 2, 3, 4, 5]
```
