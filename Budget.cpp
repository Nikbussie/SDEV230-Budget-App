#include "Budget.h"

void Budget::setIncomeCents(long long cents) {
   monthlyIncomeCents = cents;
}

long long Budget::incomeCents() const {
   return monthlyIncomeCents;
}

long long Budget::needsCents() const {
   return (monthlyIncomeCents * 50 + 50) / 100;
}

long long Budget::wantsCents() const {
   return (monthlyIncomeCents * 30 + 50) / 100;
}

long long Budget::savingsCents() const {
   return monthlyIncomeCents - needsCents() - wantsCents();
}
