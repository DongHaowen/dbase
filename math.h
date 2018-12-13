#pragma once

template<class T>
inline const T& max(const T& l,const T& r){
    return (l<r)? r:l;
}

template<class T>
inline const T& min(const T& l,const T& r){
    return (l<r)? l:r;
}