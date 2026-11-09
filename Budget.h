#ifndef BUDGET_H
#define BUDGET_H

class Budget {
public:
   void setIncomeCents(long long cents);
   long long incomeCents() const;
   long long needsCents() const;
   long long wantsCents() const;
   long long savingsCents() const;

private:
   long long monthlyIncomeCents = 0;
};

#endif
