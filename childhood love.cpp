This question was based on Euler Toitent Function. Euler’s Totient function Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
Let the count of GCD for a no from 1 to that no be phi(n), so phi(n) = n * (1-1/p1) * (1-1/p2) * ........* (1-1/pk). where p1,p2,....,pk are
the prime factors of the n.

Now, count of divisors for any is approx. equal to (N)^1/3. Since, upper bound of N is 10^12, so there will be atmost 10^4 divisors. And 
calculating distinct prime no for all the no will take place in o(n^1/2).

So, here is the algorithm to solve the question.

step 1-> Find all the divisors of the given no in O(n^1/2).

step 2-> Iterate through each diviors and find its prime factors.

Step 3-> For each no and its prime factors use the Euler's Toitent Function.

Below is the code in C++.

#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long int
#define F first
#define S second
#define mod 1000000007
#define pb push_back


int main()
{
    ll n;
    cin>>n;
    vector<ll>v;
    // Find the perfect divisors of n
    for(ll i=1;i*i<=n;++i){
        if(n%i==0) {
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    ll ans=1;
    for(ll i=0;i<v.size();++i){
        double p=v[i]*1.0;
        ll var=v[i];
        for(ll j=2;j*j<=var;j++){ // Loop to check for prime factors
            if(var%j==0){
                while(var%j==0) var/=j;
                p*=(1-(1/(double)j));     // Euler's Toitent Function
            }
        }
        if(var>1) p*=(1-(1/(double)var));   // If the no is prime itself
        ll va=p;
        ans=(ans* (va%mod))%mod;
    }
    cout<<ans%mod;  // Final answer
}
