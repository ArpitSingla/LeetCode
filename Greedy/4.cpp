No offense but the currently highest voted java solution is not ideal, the sorting can be adjusted so that there's no need to check again in the for loop.

Idea:
We know that eventually we have to shoot down every balloon, so for each ballon there must be an arrow whose position is between balloon[0] and balloon[1] inclusively. Given that, we can sort the array of balloons by their ending position. Then we make sure that while we take care of each balloon in order, we can shoot as many following balloons as possible.

So what position should we pick each time? We should shoot as to the right as possible, because since balloons are sorted, this gives you the best chance to take down more balloons. Therefore the position should always be balloon[i][1] for the ith balloon.

This is exactly what I do in the for loop: check how many balloons I can shoot down with one shot aiming at the ending position of the current balloon. Then I skip all these balloons and start again from the next one (or the leftmost remaining one) that needs another arrow.

Example:

balloons = [[7,10], [1,5], [3,6], [2,4], [1,4]]
After sorting, it becomes:

balloons = [[2,4], [1,4], [1,5], [3,6], [7,10]]
So first of all, we shoot at position 4, we go through the array and see that all first 4 balloons can be taken care of by this single shot. Then we need another shot for one last balloon. So the result should be 2.

Here I provide a concise template that I summarize for the so-called "Overlapping Interval Problem", e.g. Minimum Number of Arrows to Burst Balloons, and Non-overlapping Intervals etc. I found these problems share some similarities on their solutions.

Sort intervals/pairs in increasing order of the start position.
Scan the sorted intervals, and maintain an "active set" for overlapping intervals. At most times, we do not need to use an explicit set to store them. Instead, we just need to maintain several key parameters, e.g. the number of overlapping intervals (count), the minimum ending point among all overlapping intervals (minEnd).
If the interval that we are currently checking overlaps with the active set, which can be characterized by cur.start > minEnd, we need to renew those key parameters or change some states.
If the current interval does not overlap with the active set, we just drop current active set, record some parameters, and create a new active set that contains the current interval.
int count = 0; // Global parameters that are useful for results.
int minEnd = INT_MAX; // Key parameters characterizing the "active set" for overlapping intervals, e.g. the minimum ending point among all overlapping intervals.
sort(points.begin(), points.end()); // Sorting the intervals/pairs in ascending order of its starting point
for each interval {
      if(interval.start > minEnd) { // If the 
	 // changing some states, record some information, and start a new active set. 
	count++;
	minEnd = p.second;
      }
     else {
	// renew key parameters of the active set
	minEnd = min(minEnd, p.second);
      } 
 }
return the result recorded in or calculated from the global information;
For example, for the problem Minimum "Number of Arrows to Burst Balloons", we have

Sort balloons in increasing order of the start position.
Scan the sorted pairs, and maintain a pointer for the minimum end position for current "active balloons", whose diameters are overlapping.
When the next balloon starts after all active balloons, shoot an arrow to burst all active balloons, and start to record next active balloons.
int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto& p: points) {
            if(p.first > minEnd) {count++; minEnd = p.second;}
            else minEnd = min(minEnd, p.second);
        }
        return count + !points.empty();
    }
For the problem "Non-overlapping Intervals", we have

int eraseOverlapIntervals(vector<Interval>& intervals) {
        int total = 0, minEnd = INT_MIN, overNb = 1;
        sort(intervals.begin(), intervals.end(), [&](Interval& inter1, Interval& inter2) {return inter1.start < inter2.start;});
        for(auto& p: intervals) {
            if(p.start >= minEnd) {
                total += overNb-1;
                overNb = 1;
                minEnd = p.end;
            }
            else {
                overNb++;
                minEnd = min(minEnd, p.end);
            }
        }
        return total + overNb-1;
    }