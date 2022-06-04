#include <iostream>
#include "LinkedList.h"
#include <cmath>

// Works OK
LinkedList<int> * sieveOfEratosthenes(int n){
    auto * numbers =  new LinkedList<int>();
    auto * actives = new LinkedList<bool>();
    for (int i = 0; i <= n; ++i) {
        actives->append(true);
    }
    for (int i = 2; i <= sqrt(n) ; ++i) {
        if(actives->get(i)){
            for (int j = i*i; j <= n; j+=i) {
                actives->replace(j, false);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if(actives->get(i))
            numbers->append(i);
    }
    return numbers;
}


//Works ok on ints
void printList(LinkedList<int> * list){
    if(list->size() > 0){
        printf("[%d", list->get(0));
        for (int i = 1; i < list->size(); ++i) {
            printf(", %d", list->get(i));
        }
        printf("]\n");
    }
    else{
        printf("[]\n");
    }
}

void printSingleSum(LinkedList<int> * elementsOfSum){
    if(elementsOfSum->size() != 0){
        printf("%d",elementsOfSum->get(0));
        for (int i = 1; i < elementsOfSum->size(); i++) {
            printf("+%d",elementsOfSum->get(i));
        }
        printf("\n");
    }
    else{
        printf("List is empty!\n");
    }
}

LinkedList<int> * copy(LinkedList<int> * list){
    auto * newList = new LinkedList<int>();
    for (int i = 0; i < list->size(); ++i) {
        newList->append(list->get(i));
    }
    return newList;
}

bool contains(LinkedList<LinkedList<int>*> * listOfLists, LinkedList<int> * list){
for (int i = 0; i <listOfLists->size() ; ++i) {
if(listOfLists->get(i)->compare(list)){
return true;
}
}
return false;
}


void printSums(LinkedList<LinkedList<int>*> * listOfLists, int n, int primeIndex, LinkedList<int> * elementsOfSum, LinkedList<int> * primes){
int maxPrime = primes->get(primeIndex);
if(n != 1){
if(n >= maxPrime){
auto * newElementsOfSums = copy(elementsOfSum);
newElementsOfSums->append(maxPrime);
n -= maxPrime;
for (int i = primeIndex; i >= 0; --i) {
printSums(listOfLists, n, i, newElementsOfSums, primes);
}
}
else if(n == 0){
if(!contains(listOfLists, elementsOfSum)){
listOfLists->append(elementsOfSum);
}
}
}
}

bool isPrime(int n){
    if(n == 0 || n == 1){
        return false;
    }
    else if(n == 2){
        return true;
    }
    else{
        for (int i = 2; i <= floor(sqrt(n)); ++i) {
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}

void inputData(){
    int t, n, maxPrime;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &maxPrime);
        if(!isPrime(maxPrime)){
            continue;
        }
        LinkedList<int> * primes = sieveOfEratosthenes(maxPrime);
        auto  * list = new LinkedList<int>();
        auto * listOfLists = new LinkedList<LinkedList<int>*>();
        printSums(listOfLists, n, primes->size()-1, list, primes);
        for (int j = listOfLists->size()-1; j >= 0; --j) {
            auto * currentList = listOfLists->get(j);
            printSingleSum(currentList);
        }
    }
}

int main() {
    inputData();

    return 0;
}