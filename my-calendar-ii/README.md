# My Calendar II

Good question. Not sure how to solve it with a segment tree, but with the intervals logic, just check if they overlap and then you can put the overlapped part into the doubleBookings. The first thing you check is if there is overlap with the current doubleBookings, and if so just return false. If not, then you check if there is overlap with the current bookings, and if so, add **the overlap** to the doubleBookings. Even if there is overlap, you still add it to the bookings, because it is still a valid booking.
