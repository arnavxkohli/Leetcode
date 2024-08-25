# Task Scheduler

This is a good question, requires a bit of thinking. The main idea is you always want to try to schedule tasks which have the most frequency, and if you can't you can put them onto a "cooldown" queue. At each cycle you do two things:
1. Schedule the next item in the priority queue. If there are more items for this task, then add this task to the cooldown queue for later, and continue processing the next items.
2. Check if the first item of the cooldown queue has completed it's cooldown. If it has you can pop it off and add it to the priority queue, to be scheduled for the next cycle.