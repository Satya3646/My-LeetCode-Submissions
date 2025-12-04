class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n-1; // Start and end of the string
        while(i < n && directions[i] == 'L') // Ignore leading cars going to left since they can't collide
            i++;
        while(j >= 0 && directions[j] == 'R') // Ignore trailing cars going to right since they can't collide
            j--;
        // Other than the leading and trainling car that leave safely all other cars will collide
        // Bacause even on collidion will leave the car immovable and at the same place 
        // The collided cars dont disappear so that leads to collision of all the cars 
        int ans = 0;
        while(i <= j)
            ans += (directions[i] != 'S'),
            i++;
        // The trick here is take a segment "RSL" first right will collide with S to give one 
        // collision and then the left will also collide with them to produce one collision 
        // so the net of the segment is still 2 collisions since one R and one L is there
        // The effective answer is the number of non stationery cars in the string
        return ans;
    }
};