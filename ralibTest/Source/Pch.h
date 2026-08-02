#pragma once

// std
#include <cstdio>
#include <cassert>

// raylib
#include <raylib.h>
#include <raymath.h>

// 数学
#include "Math/Capsule.h"
#include "Math/Sphere.h"
#include "Math/ColorOperation.h"
#include "Math/Vector2Operation.h"
#include "Math/Vector3Operation.h"
#include "Math/Line.h"
#include "Math/CrtOperation.h"

#include "Object/Object.h"


// ログ
#include <filesystem>
#include "Logger/SystemLogger.h"
//LOG_TRACE,          // Trace logging, intended for internal use only
//LOG_DEBUG,          // Debug logging, used for internal debugging, it should be disabled on release builds
//LOG_INFO,           // Info logging, used for program execution info
//LOG_WARNING,        // Warning logging, used on recoverable failures
//LOG_ERROR,          // Error logging, used on unrecoverable failures
//LOG_FATAL,          // Fatal logging, used to abort program: exit(EXIT_FAILURE)
#define TRACE_LOG(text, ...) SystemLogger::Print(std::source_location::current().function_name(), __LINE__, LOG_TRACE, text, __VA_ARGS__)
#define DEBUG_LOG(text, ...) SystemLogger::Print(std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__, LOG_DEBUG, text, __VA_ARGS__)
#define INFO_LOG(text, ...) SystemLogger::Print(std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__, LOG_INFO, text, __VA_ARGS__)
#define WARNING_LOG(text, ...) SystemLogger::Print(std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__, LOG_WARNING, text, __VA_ARGS__)
#define ERROR_LOG(text, ...) SystemLogger::Print(std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__, LOG_ERROR, text, __VA_ARGS__)
#define FATAL_LOG(text, ...) SystemLogger::Print(std::filesystem::path(__FILE__).filename().string().c_str(), __LINE__, LOG_FATAL, text, __VA_ARGS__)

// アサート
#define ASSERT_TRACE_LOG(condition, text, ...) if (!(condition)) { TRACE_LOG(text, __VA_ARGS__); }
#define ASSERT_DEBUG_LOG(condition, text, ...) if (!(condition)) { DEBUG_LOG(text, __VA_ARGS__); }
#define ASSERT_INFO_LOG(condition, text, ...) if (!(condition)) { INFO_LOG(text, __VA_ARGS__); }
#define ASSERT_WARNING_LOG(condition, text, ...) if (!(condition)) { WARNING_LOG(text, __VA_ARGS__); }
#define ASSERT_ERROR_LOG(condition, text, ...) if (!(condition)) { ERROR_LOG(text, __VA_ARGS__); }
#define ASSERT_FATAL_LOG(condition, text, ...) if (!(condition)) { FATAL_LOG(text, __VA_ARGS__); }
