/**
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

/**
class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) {
        //Sorting
        sort(arr, arr+n, [](Job& a, Job& b){
            return a.profit > b.profit;
        });
        
        //Finding Maximum Deadline
        int maxDeadline = 0;
        for(int i = 0; i<n; i++){
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }
        
        //Initializing Slots array
        vector<int> slot(maxDeadline+1, -1);
        
        //Main Code
        int jobCount = 0;
        int maxProfit = 0;
        for(int i = 0; i<n; i++){
            for(int j = arr[i].deadline; j >= 1; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    jobCount++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobCount,maxProfit};
    }
};
*/
