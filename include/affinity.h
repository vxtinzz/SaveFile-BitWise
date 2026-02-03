#ifndef AFFINITY_H
#define AFFINITY_H

typedef struct {
    int attacker;
    int target;
    float multiplier;
} AffinityRules;

extern AffinityRules AFFINITYRULES[];
extern const int AFFINITY_COUNT;

#endif