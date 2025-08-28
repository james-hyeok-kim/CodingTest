#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    /**
     * @brief 완주하지 못한 선수의 이름을 찾는 함수
     * @param participant 마라톤 참가자 명단
     * @param completion 마라톤 완주자 명단
     * @return 완주하지 못한 선수의 이름
     */
    std::string findNonCompleter(const std::vector<std::string>& participant, const std::vector<std::string>& completion) {
        // 1. 참가자 명단을 해시 테이블(unordered_map)에 저장합니다.
        // 동명이인이 있을 수 있으므로, 이름(string)을 키로, 등장 횟수(int)를 값으로 저장합니다.
        std::unordered_map<std::string, int> participantMap;
        for (const std::string& name : participant) {
            participantMap[name]++; // 해당 이름의 카운트를 1 증가시킵니다.
        }

        // 2. 완주자 명단을 순회하며 해시 테이블에서 해당 선수의 카운트를 1 감소시킵니다.
        for (const std::string& name : completion) {
            participantMap[name]--;
        }

        // 3. 해시 테이블을 다시 순회하여 값이 0이 아닌 (즉, 1인) 선수를 찾습니다.
        // 이 선수가 바로 완주하지 못한 선수입니다.
        for (const auto& pair : participantMap) {
            if (pair.second > 0) {
                return pair.first; // 완주하지 못한 선수의 이름을 반환합니다.
            }
        }
        
        // 이론적으로는 이 라인에 도달하지 않아야 하지만, 컴파일러 경고를 피하기 위해 추가합니다.
        return ""; 
    }
};

// 테스트를 위한 main 함수
int main() {
    Solution sol; // Solution 클래스의 인스턴스 생성

    // 예제 1
    std::vector<std::string> participant1 = {"leo", "kiki", "eden"};
    std::vector<std::string> completion1 = {"eden", "kiki"};
    std::cout << "Test Case 1 Result: " << sol.findNonCompleter(participant1, completion1) << std::endl; // 예상 결과: "leo"

    // 예제 2 (동명이인 포함)
    std::vector<std::string> participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
    std::vector<std::string> completion2 = {"josipa", "filipa", "marina", "nikola"};
    std::cout << "Test Case 2 Result: " << sol.findNonCompleter(participant2, completion2) << std::endl; // 예상 결과: "vinko"

    // 예제 3 (동명이인 완주 실패)
    std::vector<std::string> participant3 = {"mislav", "stanko", "mislav", "ana"};
    std::vector<std::string> completion3 = {"stanko", "ana", "mislav"};
    std::cout << "Test Case 3 Result: " << sol.findNonCompleter(participant3, completion3) << std::endl; // 예상 결과: "mislav"

    return 0;
}
