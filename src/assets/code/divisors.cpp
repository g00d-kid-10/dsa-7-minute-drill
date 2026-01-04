// Only need to loop to sqrt(num) => derasticaly reduces time complexity from O(n) -> O(sqrt(n))
// While looping when one element is found divisor the other pair num / i 
// is evidently available past the point of sqrt(num) in range (sqrt(num), num)
// which you are not exploring through the loop and save the time

vector<int> find_divisors(int num) {
    vector<int> divisors;
    for(int i = 1; i * i <= num; i++) {                       
        if(num % i == 0) {
            divisors.push_back(i);
            if(num / i != i)
                divisors.push_back(num / i);
        }
    }

    return divisors;
}