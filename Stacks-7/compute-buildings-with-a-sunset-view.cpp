// https://backtobackswe.com/platform/content/compute-buildings-with-a-sunset-view/code

class Solution {
  public:
    vector<int> getBuildingsWithAView(vector<int>& buildings) {
 
    vector<int> sunsetViewBldg;
    sunsetViewBldg.emplace_back(0);
    // Start traversing element
    int curr_max = buildings[0];
    for (int i = 1; i < buildings.size(); i++) {
       
        // If curr_element is maximum
        // or current element is
        // equal, update maximum and increment count
        if (buildings[i] > curr_max) {
            sunsetViewBldg.emplace_back(i);
            curr_max = buildings[i];
        }
    }
 
    return sunsetViewBldg;
  }
};
