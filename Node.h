#pragma once

template <typename T>
struct Node1w
{
	T _info;
	Node1w* _next;

	Node1w(const T& info, Node1w* next = nullptr) : _info{ info }, _next{ next } {}
};

template <typename T>
struct Node2w
{
	T _info;
	Node2w* _prev;
	Node2w* _next;

	Node2w(const T& info, Node2w* prev = nullptr, Node2w* next = nullptr) : _info{ info }, _prev{ prev }, _next{ next } {}
};
