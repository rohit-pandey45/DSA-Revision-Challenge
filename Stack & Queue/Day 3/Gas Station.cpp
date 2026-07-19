/**
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n = gas.size();
      
        // Start from the last gas station.
        int start = n - 1;
      
        // 'j' will be used to traverse the gas stations.
        int j = n - 1;
      
        // 'tours' will count how many gas stations we have considered.
        int tours = 0;
      
        // 'totalFuel' will keep track of our current fuel balance.
        int totalFuel = 0;

        // Loop through the gas stations to see where we can start.
        while (tours < n) {
            // Add net fuel (after consuming cost) at the current station.
            totalFuel += gas[j] - cost[j];
          
            // Move to the next gas station.
            tours++;
            j = (j + 1) % n;
          
            // If our total fuel goes negative, move start one station backward
            // and add the net fuel at that station to 'totalFuel'.
            while (totalFuel < 0 && tours < n) {
                // Only able to move backward if the total number of steps
                // considered is less than the number of gas stations.
                start--;
                totalFuel += gas[start] - cost[start];
              
                // Another station considered.
                tours++;
            }
        }
      
        // If after considering all stations the 'totalFuel' is still negative,
        // there is no way to complete the circuit. Otherwise, return the starting station.
        return totalFuel < 0 ? -1 : start;
    }
};
    
 */