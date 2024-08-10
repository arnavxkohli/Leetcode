# House Robber

Simple dynamic programming question, There are two choices we can make at any index. Either rob or don't rob.
1. Rob: If we choose to rob, then we can take the money from this house and add it to the max amount we would've got 2 houses ago
2. Don't Rob: If we don't choose to rob, then we have to keep the same amount we had from robbing one house ago.

At each decision point, we have to take the maximum of these two. Nothing more complicated than that.
