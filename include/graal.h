#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstdlib>
#include <cstring>
#include <iterator>

namespace graal {

    /*!
     *
     * \param first Inicio do range.
     */
    void transform( void *first, void *last, std::size_t size, void (*func) ( void * ) );

    const void *find( void *first, void *last, std::size_t,
                const void * target, bool (*eq)( const void*, const void* ) );
    const void *find_if( void *first, void *last, bool (*p)( const void* ), std::size_t size );
    bool all_of( const void * first , const void * last ,  std::size_t size, bool (*p) (const void *) );
	bool any_of( const void * first , const void * last ,  std::size_t size, bool (*p) (const void *) );
	bool none_of( const void * first , const void * last ,  std::size_t size, bool (*p) (const void *) );

    void *min( const void * first, const void *last, bool (*cmp) (const void *, const void *), std::size_t size);
    void *copy( const void * first, const void *last, const void * n_first, std::size_t size );
    void *copy_if( const void * first, const void *last, const void * n_first,  bool (*p) (const void *), std::size_t size );
    void *unique( const void *first, const void *last, bool (*cmp) (const void *, const void *), std::size_t size);
    void reverse( void * first, void * last, std::size_t size);
    void *remove_if( const  void * first, const void * last, bool (*p) (const void *), std::size_t size);
	void *partition ( void * first , void * last , size_t size , bool (*p) (const void *) );
    void *partition_quick( void * first , void * last , size_t size , bool (*cmp) (const void *, const void*) );
    void *merge( const void *first_a, void *last_a, void *first_b, void *last_b, void *first_c, 
                bool (*cmp) (const void *, const void*), std::size_t size);

    void *binary_search( const void * first, const void *last, const void * key, 
                bool (*cmp) (const void *, const void*), bool (*cmpp) (const void *, const void*), std::size_t size);

    void sorted_insertion( const void *first, const void *last_, const void *last, const void *new_element,
      bool (*cmp) (const void *, const void*), std::size_t size);

    /**-------Sorting algorithms--------**/
    void selection_sort(const void *first, const void *last, bool (*cmp) (const void*, const void *), std::size_t size);
    void insertion_sort( const void *first, const void *last,  bool (*cmp) (const void*, const void *), std::size_t size);
    void bubble_sort( const void *first, const void *last, bool (*cmp) (const void*, const void *), std::size_t size);
    void quick_sort( void *first, void *last, bool (*cmp) (const void *, const void*), std::size_t size);
    void merge_sort( const void *first, const void *last, bool (*cmp) (const void *, const void*), std::size_t size);
}

#endif
