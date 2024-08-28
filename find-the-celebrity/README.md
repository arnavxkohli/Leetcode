# Find the Celebrity

The logic is a bit unintuitive and hard to think of. You can obviously check each and every person and see if they know anyone and if everyone knows them with a set and adjacency list (in degree like topo sort), but this is excessive.

Since you are guaranteed a celebrity, start with the first person as the candidate. As you go through all the people ask if they know the `i`th person. If they do, they can't be a celebrity but `i` still can. When you finish up the loop you will be left with the only person who can still be a celebrity based on disqualification by knowing someone.

The only person can still be disqualified if the person they knew was in the range `[:i]`. Or if someone didn't know them.
To check for this, go through the entire array with your only remaining candidate. If any of the two conditions above comes true, then they are not the candidate.
