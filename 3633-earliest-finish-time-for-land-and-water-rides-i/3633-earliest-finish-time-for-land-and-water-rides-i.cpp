class Solution {
public:
    long long earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        long long minLandFinish = -1;
        for (size_t i = 0; i < landStartTime.size(); ++i) {
            long long finish = (long long)landStartTime[i] + landDuration[i];
            if (minLandFinish == -1 || finish < minLandFinish) {
                minLandFinish = finish;
            }
        }
        
        long long minWaterFinish = -1;
        for (size_t j = 0; j < waterStartTime.size(); ++j) {
            long long finish = (long long)waterStartTime[j] + waterDuration[j];
            if (minWaterFinish == -1 || finish < minWaterFinish) {
                minWaterFinish = finish;
            }
        }
        
        long long landThenWater = -1;
        for (size_t j = 0; j < waterStartTime.size(); ++j) {
            long long currentFinish = std::max(minLandFinish, (long long)waterStartTime[j]) + waterDuration[j];
            if (landThenWater == -1 || currentFinish < landThenWater) {
                landThenWater = currentFinish;
            }
        }
        
        long long waterThenLand = -1;
        for (size_t i = 0; i < landStartTime.size(); ++i) {
            long long currentFinish = std::max(minWaterFinish, (long long)landStartTime[i]) + landDuration[i];
            if (waterThenLand == -1 || currentFinish < waterThenLand) {
                waterThenLand = currentFinish;
            }
        }
        
        return std::min(landThenWater, waterThenLand);
    }
};