:- use_module(library(pita)).

:- if(current_predicate(use_rendering/1)).
:- endif.

:- pita.
:- begin_lpad.

legit(Merge): 0.3; non_legit(Merge) : 0.7:-request(Merge),\+trusty(Merge).
% if we request a Merge that is not trusty then it provides legit with probability 0.3
% and non_legit with probability 0.7
legit(Merge): 0.9 ; non_legit(Merge) : 0.1:-request(Merge),trusty(Merge).
% if we request a Merge that is trusty then it provides legit with probability 0.9
% % and non_legit with probability 0.1
trusty(Merge):0.9 ; not_trusty(Merge):0.1.
% a Merge is fair with probability 0.9 and trusty with probability 0.1
request(Merge).
% Merge is certainly requested

:- end_lpad. 