#pragma once

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>

template <typename Container>
void bubble(Container& container);

template <typename Container>
void insertion(Container& container);

template <typename Container>
void quick(Container& container);

template <typename Container>
void merge(Container& container);

template <typename Container>
void prints(const Container& container);