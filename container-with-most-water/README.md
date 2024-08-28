# Container with Most Water

The most basic two pointers question. Increment the left pointer if you lose out on the massive r height, and decrement the right pointer if you lose out on the massive l height. Basically keep the greater of the two heights in hope for a height even greater so that you can have the greatest min height between the two. Slightly confusing. Just implement/see the implementation and you will know.

This is also because you are aiming to maximize the function `min(height[l], height[r]) * (r-l)`. So you want to keep the greater of the two heights because if the minimum changes between iterations you don't lose much, but if the maximum changes it's good.
