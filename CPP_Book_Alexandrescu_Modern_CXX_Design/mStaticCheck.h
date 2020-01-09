#pragma once

template <bool> struct CompileTimeError;
template <> struct CompileTimeError<true> {};

#define STATIC_CHECK(expr)(CompileTimeError<(expr) != 0>())
