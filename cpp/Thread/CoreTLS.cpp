#include "pch.h"
#include "Thread/CoreTLS.h"

thread_local unsigned int LThreadId = 0;
thread_local JobSerializer* LCurrentSerializer = nullptr;