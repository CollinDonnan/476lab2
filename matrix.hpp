/*
  Filename   : Matrix.hpp
  Author     : Collin Donnan
  Course     : CSCI 476
  Date       : 2/20/26
  Assignment :
  Description: Class for representing square matrices of order
               N (i.e., N x N).
*/

/************************************************************/
// Prevent multiple inclusion

#pragma once

/************************************************************/
// System includes

#include <algorithm>
#include <memory>
#include <new>

/************************************************************/

template<typename T>
class Matrix
{
public:
  using iterator = T*;
  using const_iterator = T const*;

  /**********************************************************/

  // Delete default ctor. User should always specify a size.
  Matrix () = delete;

  /**********************************************************/

  // Initialize a square matrix of order 'order'.
  Matrix (unsigned order)
    : // TODO
  {
  }

  /**********************************************************/

  // Copy ctor.
  // Use a delegating ctor.
  Matrix (Matrix const& m)
      : Matrix (/* TODO */)
  {
    // TODO
  }

  /**********************************************************/

  // Move ctor. 
  Matrix (Matrix&& m) noexcept
    : // TODO
  {
  }

  /**********************************************************/

  // Dtor. Default is fine thanks to std::unique_ptr!
  ~Matrix () = default;

  /**********************************************************/

  // Swap matrix objects. Use in other methods. 
  void
  swap (Matrix& other) noexcept
  {
    using std::swap;
    swap (m_data, other.m_data);
    swap (m_order, other.m_order);
  }

  /**********************************************************/

  // Copy assignment.
  // Use copy swap idiom.
  Matrix&
  operator= (Matrix m)
  {
    // TODO
    return *this;
  }

  /**********************************************************/

  // Move assignment.
  // Use copy swap idiom.
  Matrix&
  operator= (Matrix&& m) noexcept
  {
    // TODO
    return *this;
  }

  /**********************************************************/

  // Return the appropriate element
  // Do NOT do bounds checking
  T&
  operator[] (unsigned row, unsigned col)
  {
    // TODO
  }

  /**********************************************************/

  // Return the appropriate element
  // Do NOT do bounds checking
  T const&
  operator[] (unsigned row, unsigned col) const
  {
    // TODO
  }

  /**********************************************************/

  // Return the order
  unsigned
  order () const
  {
    // TODO
  }

  /**********************************************************/

  // Return the number of elements
  size_t
  size () const
  {
    // TODO
  }

  /**********************************************************/

  // Return pointer to first element
  iterator
  begin ()
  {
    // TODO
  }

  /**********************************************************/

  // Return pointer to first element
  const_iterator
  begin () const
  {
    // TODO
  }

  /**********************************************************/

  // Return pointer to one beyond last element
  iterator
  end ()
  {
    // TODO
  }

  /**********************************************************/

  // Return pointer to one beyond last element
  const_iterator
  end () const
  {
    // TODO
  }

  /**********************************************************/

private:
  static constexpr std::align_val_t CACHE_LINE_BYTES { 64 };

private:
  std::unique_ptr<T[]> m_data;
  unsigned m_order;
};

/************************************************************/