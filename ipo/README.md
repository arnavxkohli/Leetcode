# IPO

Two heaps, greedy algorithm. Basically find the minimum cost with the maximum profits in the beginning with one min heap, and then keep adding all possible IPOs that we can take part in by putting them on the max heap with the maximum profit during that iteration at the top. Just make sure to early return in case we can't take part in any IPOs.
