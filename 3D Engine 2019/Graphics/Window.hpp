#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ostream>

#include "Graphics.hpp"

namespace Graphics{
    class Window// : _obj_debugable
    {
        public:
            Window();
            virtual ~Window();

            std::ostream& print(std::ostream& os) const{
                os << "(Fenetre)" ;
                return os ;
            };
        protected:

        private:
    };
}
#endif // WINDOW_HPP
