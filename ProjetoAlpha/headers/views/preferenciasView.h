//
// Created by jppmm on 13/06/2024.
//

#ifndef HEADERS_VIEWS_PREFERENCIAVIEW_H_
#define HEADERS_VIEWS_PREFERENCIAVIEW_H_

#include <list>
#include "preferencias.h"

class PreferenciaView {
public:
    Preferencia getPreferencia();
    void printPreferencia(const Preferencia& preferencia) const;
    void printPreferencias(const std::list<Preferencia>& preferencias) const;
};

#endif /* HEADERS_VIEWS_PREFERENCIAVIEW_H_ */

