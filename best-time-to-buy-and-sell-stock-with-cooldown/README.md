# Best time to buy and sell stock with cooldown

There are two solutions I have formed - both along the same lines. I will explain the thought process behind the first and better solution.

At each index, you can either buy, sell or cooldown with some constraints. This can be modelled as `(index, can_buy)` state, where `index` is the current index and `can_buy` is `True` if you aren't holding any stock
1. If you can buy: Then buy and convert `can_buy` to `False` for the next index, or don't buy, keep the `can_buy` as `True` but increment the index to show that you are cooling down
2. If you can't buy: Then sell and cooldown for a day incrementing the index by 2 and resetting `can_buy` to `True`, or keep `can_buy` as `False` and wait a day (`index+1`).

This is a much simpler approach than keeping the previous bought price

The trick that allows this optimization is the fact that buying a price means going into debt -> so you are basically going to negative profit if you buy, and you are adding profit if you sell.

This means -> buying is `-prices[index]` and selling is `+prices[index]`
