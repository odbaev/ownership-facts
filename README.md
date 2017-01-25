# ownership-facts

Извлечение фактов владения собственностью (используется [Томита-парсер](https://tech.yandex.ru/tomita/)).

Подробное описание в [отчете](отчет.pdf).

## Использование

В файле [text.txt](text.txt) задается текст.
В папке [dicts](dicts) находятся файлы с персонами и организациями, присутствующими в тексте:
* [surnames.txt](dicts/surnames.txt), [names.txt](dicts/names.txt), [patronymics.txt](dicts/patronymics.txt) - ФИО персон
* [org_names.txt](dicts/org_names.txt) - названия организаций

### Запуск

    tomitaparser src/config.proto
    
### Результат

В файле [output/facts.xml](output/facts.xml) содержатся извлеченные факты.
