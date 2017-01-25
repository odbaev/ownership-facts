#encoding "utf-8"
#GRAMMAR_ROOT S

#define dicts ['name','surname','patronymic','org_name']

Person -> (Word<kwtype='surname'> interp (Ownership.Owner_surname))
          Word<kwtype='name'> interp (Ownership.Owner_name)
          (Word<kwtype='patronymic'> interp (Ownership.Owner_patronymic));

Person -> (Word<kwtype='name'> interp (Ownership.Owner_name))
          Word<kwtype='surname'> interp (Ownership.Owner_surname);

Person -> Word<kwtype='name'> interp (Ownership.Owner_name)
          Word<kwtype='patronymic'> interp (Ownership.Owner_patronymic)
          Word<kwtype='surname'> interp (Ownership.Owner_surname);

Initial -> Word<wff=/[А-Я]\./>;
Initials -> Initial interp (Ownership.Owner_name) 
          (Initial interp (Ownership.Owner_patronymic));

Person -> Initials Word<kwtype='surname'> interp (Ownership.Owner_surname);

Org -> Word<kwtype='org_name'>;
Family -> "семья" Word<kwtype='surname'>;

FamilyOwner -> Family interp (Ownership.Owner_org_name);
OrgOwner -> Org interp (Ownership.Owner_org_name) | FamilyOwner;

Property -> Org interp (Ownership.Property);

And -> Comma | SimConjAnd;
NextProperty -> And AnyWord<kwtype=~'org_name'>* Property;
Properties -> Property NextProperty*;

Owns -> "основатель" | "владелец" | "совладелец" | "соучредитель" | "создатель" | "собственник" | "хозяин" | 
        "основать" | "владеть" | "создать" | "принадлежать" | "открыть" | "подконтрольный" | "входить" | "доля";


S -> Owns Word<kwtype=~'org_name'>* Properties Person;
S -> Owns Person Properties;
S -> Person AnyWord<kwset=~['name','surname','patronymic']>* Owns AnyWord<kwtype=~'org_name'>* Property;
S -> Property AnyWord<kwset=~${dicts}>* Owns AnyWord<kwset=~${dicts}>* OrgOwner;
S -> FamilyOwner AnyWord<kwset=~${dicts}>* Owns AnyWord<kwset=~${dicts}>* Property;
S -> Person<gram="род"> Property;
S -> "продать" Property Person<gram="дат">;
