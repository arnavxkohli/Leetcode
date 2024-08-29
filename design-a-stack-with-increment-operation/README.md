# Design a Stack With Increment Operation

The only trick here really is the increment operation. Notice that at any one point in time, you are only accessing the top of the stack. So you can "lazily increment". Just maintain for the top if k > occupancy and for k if otherwise. While popping you only need to care of incrementing the lower value, which makes increment an O(1) operation.
