// This file was generated by colf(1); DO NOT EDIT
// The compiler used schema file test.colf.

#ifndef GEN_COLFER_H
#define GEN_COLFER_H

#include <cstddef>

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

// Package gen tests all field mapping options.
namespace gen {

// colfer_size_max is the upper limit for serial octet sizes.
extern std::size_t colfer_size_max;

// colfer_list_max is the upper limit for the number of elements in a list.
extern std::size_t colfer_list_max;

// O contains all supported data types.
struct O {
	// b tests booleans.
	bool b;

	// u8 tests unsigned 8-bit integers.
	std::uint8_t u8;

	// u16 tests unsigned 16-bit integers.
	std::uint16_t u16;

	// u32 tests unsigned 32-bit integers.
	std::uint32_t u32;

	// u64 tests unsigned 64-bit integers.
	std::uint64_t u64;

	// i32 tests signed 32-bit integers.
	std::int32_t i32;

	// i64 tests signed 64-bit integers.
	std::int64_t i64;

	// f32 tests 32-bit floating points.
	float f32;

	// f32s tests 32-bit floating point lists.
	std::vector<float> f32s;

	// f64 tests 64-bit floating points.
	double f64;

	// f64s tests 64-bit floating point lists.
	std::vector<double> f64s;

	// t tests timestamps.
	std::chrono::nanoseconds t;

	// a tests binaries.
	std::vector<std::uint8_t> a;

	// as tests binary lists.
	std::vector<std::vector<std::uint8_t> > as;

	// s tests text.
	std::string s;

	// ss tests text lists.
	std::vector<std::string> ss;

	// o tests nested data structures.
	O* o;

	// os tests data structure lists.
	std::vector<O> os;

	// marshal_len returns the Colfer serial byte size.
	std::size_t marshal_len() const;

	// marshal encodes O as Colfer into buf and returns the number of octets written.
	std::size_t marshal(void* buf) const;

	// unmarshal decodes data as Colfer and returns the number of bytes read.
	std::size_t unmarshal(const void* data, std::size_t len);
};

} // namespace gen

#include <algorithm>

#ifndef COLFER_COMMONS
namespace colfer_commons {
	inline bool float_equal(float f1, float f2) {
		return (f1 == f2) || (f1 != f1 && f2 != f2);
	}

	inline bool double_equal(double f1, double f2) {
		return (f1 == f2) || (f1 != f1 && f2 != f2);
	}
}
#endif

inline bool operator==(const gen::O& a, const gen::O& b) {
	return a.b == b.b
	    && a.u8 == b.u8
	    && a.u16 == b.u16
	    && a.u32 == b.u32
	    && a.u64 == b.u64
	    && a.i32 == b.i32
	    && a.i64 == b.i64
	    && colfer_commons::float_equal(a.f32, b.f32)
	    && a.f32s.size() == b.f32s.size()
	    && std::equal(a.f32s.begin(), a.f32s.end(), b.f32s.begin(), colfer_commons::float_equal)
	    && colfer_commons::double_equal(a.f64, b.f64)
	    && a.f64s.size() == b.f64s.size()
	    && std::equal(a.f64s.begin(), a.f64s.end(), b.f64s.begin(), colfer_commons::double_equal)
	    && a.t == b.t
	    && a.a == b.a
	    && a.as == b.as
	    && a.s == b.s
	    && a.ss == b.ss
	    && a.o == b.o
	    && a.os.size() == b.os.size()
	    && std::equal(a.os.begin(), a.os.end(), b.os.begin(), operator==);
}

inline bool operator!=(const gen::O& a, const gen::O& b) {
	return !operator==(a, b);
}

#endif
