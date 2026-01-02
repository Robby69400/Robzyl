> [**Przetłumacz 🌐**](https://translate.google.com/translate?sl=auto&tl=pl&u=https://github.com/Robby69400/Robzyl_K5/)
> ===================================================================================================================

# Oprogramowanie Quansheng UV-K5 - Robzyl

Oprogramowanie jest w języku angielskim, dostępne wersje odpowiadają krajom docelowym dla pasm: Międzynarodowy, Francja, Polska, Rumunia, Turcja, Rosja, Czechy, Brazylia. Te pasma można dostosować, skontaktuj się ze mną na Telegramie.

### 🙏 Wielkie podziękowania dla Zylka, Kolyan, Iggy, Toni, Yves i Francois

## 🗲 Youtube

## 🗲 Telegram
Od teraz kod źródłowy będzie dostępny na żądanie. Skontaktuj się ze mną na Telegramie.

# **Instrukcja Robzyl - Oprogramowanie Quansheng UV-K5**

## Wprowadzenie

To oprogramowanie, fork NUNU od NTOIVOLA, charakteryzuje się wieloma funkcjami odbioru wdrażającymi analizator spektrum zdolny do przetwarzania do 160 kanałów na sekundę. Obecnie działa tylko dla K5/K6 w V1.

⚠️ W przypadku problemu możesz użyć procedury przywracania poniżej.

## ⚠️ Ostrzeżenia i odpowiedzialność

**Dziedzina radiowa jest regulowana, każdy jest odpowiedzialny za sposób, w jaki używa swojego odbiornika.**

## Oprogramowanie Robzyl – Główne funkcje dla Quansheng K5!

🔥 Obsługa rozszerzeń EEPROM: pozwala na założenie 1000 kanałów (wymaga sterownika Chirp "512k").

⚠️ Uwaga: użyj wersji 512k tylko jeśli masz więcej niż 8 KB pamięci EEPROM!

🔍 Wiele trybów skanowania Przełączaj się między trybami skanowania częstotliwości, zakresu, pasma i listy – niezwykle elastyczne dla wszystkich sytuacji!

🎚️ Automatyczny wybór modulacji Podczas skanowania pasm lub list, modulacja jest automatycznie ustawiana (FM/AM/SSB) na podstawie informacji kanału lub zarejestrowanego pasma. Nie trzeba już ręcznego przełączania!

📊 Dynamiczny squelch Squelch bazuje na wykrywaniu szczytu i ignoruje zmienności szumu tła.

⛔ Częstotliwości do pominięcia Unikaj niepożądanych lub hałaśliwych częstotliwości podczas przyszłych skanów pojedynczym naciśnięciem.

📜 Przewijana lista historii Przejrzyj wszystkie niedawno zeskanowane częstotliwości, w tym liczbę wykryć lub czas i nazwy odpowiadających pamięci. Łatwo wróć do dowolnej częstotliwości! Zapis w EEPROM jeśli rozszerzenie jest dostępne. Wyświetla nazwę kanału w historii, jeśli częstotliwość odpowiada zarejestrowanej pamięci.

✅ 15 list skanów i 32 pasma – Wizualnie włączaj/wyłączaj swoje pasma/listy ze wskaznikami w kształcie gwiazdy. Listy pasm dostępne dla wielu krajów, ale można je dostosować na żądanie.

📡 Transmisja ze spektrum – Naciśnij PTT podczas skanowania, aby wyemitować na wybranej częstotliwości, a następnie automatycznie powrócić do skanowania.

🕒 Regulacja DelayRssi – Dostosuj szybkość skanowania, ustawiając opóźnienie przed pomiarem RSSI. Regulacja SpectrumDelay – Dostosuj opóźnienie przed wznowieniem skanowania. Regulacja MaxListenTime – Dostosuj maksymalny czas słuchania przed wznowieniem skanowania.

💾 Zapis/Wczytanie EEPROM – Parametry skanowania, pasma, poziomy squelch – wszystko jest zapisywane i wczytywane przy uruchomieniu.

😎 Tryb Ninja: przeskakiwanie częstotliwości na K5. 😜 Bips Mario, Pac-Man, R2D2 i Roger.

## 🔥 Nowości V6_TURBO

Pełne przeprojektowanie grafiki głównych ekranów!

Prealokacja przycisków na ekranach VFO/MR:

- Naciśnięcie długie 4/5/6/0 do regulacji BANDWIDTH/STEP/POWER/MODULATION.
- F + 7/8/9 do uruchomienia spektrum w trybie SCANLIST/BANDLIST/FREQUENCE. Przejście spektrum do VFO (przycisk PTT), wartości LNA są pobierane. 1000 wpisów historii dla wersji EEPROM 8k. Strojenie i różne poprawki.

## Nowości V5.5.0

Zarządzanie 1000 kanałami z wersją 512k, wymaga zmiany EEPROM. Poprawka przycisków. Zielona dioda LED nie zaświeca się, jeśli backlight < 6. Wyświetlanie AFC (Automatic Frequency Control), pozwala sprawdzić precyzyjną regulację częstotliwości. Spectrum delay zapisany i dźwięk wyciszony bez sygnału. 100 wartości historii / blacklist możliwych do przechowania w EEPROM w wersji 512k.

Nowe parametry w menu [5]:

- Max Listen Time: maksymalny czas słuchania odbieranej częstotliwości.
- RX_Backlight_ON: umożliwia aktywację podświetlenia w odbiorniku spektrum.
- CLEAR HISTORY: czyści historię EEPROM (wersja 512k).
- FREE RAM: wskazuje dostępną pamięć.

## Uruchomienie

- **Instalacja oprogramowania:**

- Pobierz najnowszą wersję z GitHub (link na końcu doc). Uważaj na wersje 8k i 512k zgodnie z Twoim EEPROM.

- Przygotuj kabel programacyjny USB kompatybilny ze stacją.

- Podłącz stację do komputera, a następnie uruchom K5, naciskając przycisk PTT.

- Następnie, ze świecącą diodą LED, prześlij oprogramowanie do K5 za pośrednictwem Flasha online lub K5prog-win (link na końcu doc).

- Jeśli przygotowujesz się do zastąpienia oprogramowania fabrycznego, zaleca się wcześniejsze zapisanie konfiguracji i kalibracji za pomocą K5prog (patrz np. film F5SVP).

- Z każdą aktualizacją wersji FW parametry spektrum są resetowane.

- **Szybkie rozpoczęcie:**

- Menu ukryte: rzadko używane menu zostały ukryte dla uproszczenia. Aby wyświetlić pełne menu, wystarczy uruchomić stację, naciskając 0.

- Programowanie za pomocą Chirp: sterownik do użycia w komunikacji ze stacją w Robzyl można pobrać (link na końcu doc). Uważaj, aby nie być w trybie spektrum, aby móc komunikować się z PC. Uważaj na wersje 8k i 512k zgodnie z Twoim EEPROM.

- Przywrócenie ostatniego stanu: po wyłączeniu K5, jego ponowne uruchomienie wznawia się w trybie aktywnym w momencie wyłączenia, biorąc pod uwagę ostatnie zapisane parametry spektrum.

- Główne funkcje specyficzne dla oprogramowania Robzyl opisano poniżej. Aby uzyskać podstawowe funkcje K5, zapoznaj się z jego dokumentacją.

## Tryby VFO i Pamięć

Te tryby są dostępne naprzemiennie poprzez długie naciśnięcie przycisku 3. Na tych ekranach długie naciśnięcia przycisków 4/5/6/0 pozwalają na regulację BANDWIDTH/STEP/POWER/MODULATION. Menu na przycisku M daje również dostęp do wszystkich tych parametrów. W odbiorniku pojawia się czasomierz czasu słuchania.

### Tryb VFO

Prosty tryb VFO pozwala na swobodne wprowadzenie częstotliwości. W odbiorniku na ekranie pojawia się wartość AFC, wartość miernika S i moc sygnału w dBm.

### Tryb MR (Pamięci)

Ten tryb pozwala na nawigację w banku 200 nazwanych pamięci K5 (lub 999 dla K5 512K). Ten bank należy przygotować i wstrzyknąć do radia z Chirp. W odbiorniku pojawia się wartość miernika S i moc sygnału w dBm.

## Tryb spektrum

### Wspólne funkcje trybu spektrum

Ekran główny:

- Linia górna: Typ spektrum (SL, FQ, BD, RG), wartość trigera squelch, opóźnienie RSSI, modulacja, poziom baterii.
- Klatka 1: 2 opcje wyświetlania informacji związanych z częstotliwością.
- Klatka 2: Graficzne przedstawienie analizowanych kanałów.
- Linia dolna: Bieżący zasięg i szczyt częstotliwości.

### Przydział przycisków

- Przycisk 1: Pominięć częstotliwość.
- Przycisk 2: Uproszczony ekran.
- Przycisk 3: Wybór szerokości pasma.
- Przycisk 4: Menu wyboru SL/BD.
- Przycisk 5: Dostęp do parametrów.
- Przycisk 6: Nawigacja w trybach.
- Przycisk 7: Zapis parametrów.
- Przycisk 8: 2 opcje wyświetlania.
- Przycisk 9: Wybór modulacji.
- Przycisk 0: Historyk.
- Przycisk M: Tryb Still.
- SIDE KEY 1: Przejście trybów.
- SIDE KEY 2: Blacklist.
- Przycisk */F: Regulacja squelch.
- Przycisk ^/v: Nawigacja.

### Menu parametrów

- RSSI Delay: czas przechwycenia RSSI.
- SpectrumDelay: Czas oczekiwania.
- Max Listen Time: Maksymalny czas słuchania.
- PTT: Opcja transmisji.
- Fstart/Fstop: Konfiguracja częstotliwości.
- Step: Kanalizacja.
- ListenBW: Szerokość pasma.
- Modulacja: FM/AM/USB.
- RX_Backlight_ON: Podświetlenie.
- Freq counting: Liczenie odborów.
- CLEAR HISTORY: Czyśczenie historii.
- FREE RAM: Pamięć.
- PowerSave: Oszczędzanie energii.
- Noislvl_OFF: Poziom szumu.
- POPUPS: Opóźnienie komunikatów.

### Uproszczona widok

Ekran oferuje bardziej syntetyczny widok trwającego skanowania, pozwalając na łatwy regulację parametrów squelch.

### Tryb Still (monitoring)

Monitoring uruchamia się przyciskiem M na częstotliwości w słuchaniu. Na tym ekranie niektóre rejestry są zmieniane dla zaawansowanych użytkowników.

### Historia częstotliwości

Historia ewoluuje dynamicznie w zależności od odbieranego sygnału. Można nawigować po liście, radio przechodzi w Frequency Lock (FL) i można słuchać bezpośrednio przechowywanych częstotliwości.

Opcje:
- M: Przejść w Frequency Lock, a następnie monitoring.
- 2: Zapisać wpę historii do pierwszej dostępnej pamięci.
- 3: Usunąć wpę historii.
- 5: Skanować wpęsy historii.
- 7: Zapisać historię w EEPROM (wersja 512k).
- 8: Wyczyścić historię z pamięci.

Specjalny tryb skanowania U00 pozwala na bardzo szybkie zbieranie historii bez zatrzymywania się w słuchaniu.

### Porady

- Wartość regulacji squelch zależy od środowiska, anteny i wyboru opóźnienia RSSI.
- RSSI Delay: rozpocznęć od przykładu 3 ms i dostosować.
- Trigger Up Uxxx: rozpocznęć od przykładu 5 i dostosować.
- Noise level: rozpocznęć od przykładu 60 i dostosować.

## Spektrum na Listach skanów (tryb SL)

- Funkcja: Ładowanie pamięci przypisanych do list skanów.
- Uruchomienie: Z trybu VFO/MR, przycisk F+4.
- Przed użyciem częstotliwości w pamięciach muszą zostać przypisane do listy skan.
- Przy pierwszym użyciu możesz nawigować w każdej SL, aby dostosować parametry squelch.
- Zapisz wartości przyciskiem 7.
- Załaduj SL do spektrum przez menu wyboru przyciskiem 4.

## Spektrum na zakresie częstotliwości (tryb FQ)

- Funkcja: Analiza gamy częstotliwości od centralnej lub określonego zakresu.
- Uruchomienie: Z trybu VFO/MR, przycisk F+5.
- Częstotliwość z VFO/MR jest przenoszona do spektrum jako centralna.
- Zasięg może być dostosowany poprzez parametry FStart/FStop.
- Dostosuj squelch.

## Spektrum na predefiniowanych pasmach (tryb BD)

- Funkcja: Analiza predefiniowanych pasm (PMR, CB, AERO, HAM, etc.).
- Uruchomienie: Z trymu VFO/MR, przycisk F+6.
- Pasma przechowywane w pliku `bands.h` (do dostosowania).
- Można zdefiniować do 32 pasm.

## Procedura przywracania

- Użyj archiw `Rollback.zip`.
- Flashuj plik `ROLLBACK.bin` w trybie prostym.
- Po flashowaniu wyłącz radio, przytrzymaj przycisk 7, następnie włącz.
- Czekaj na wyczyszczenie pamięci.
- Flashuj oryginalne oprogramowanie (`K6 v3.00.19_publish.bin`).
- Po flashowaniu wykonaj pełny reset przez menu.
- Flashuj plik kalibracji (`my_calibration.bin`).
- Użyj k5prog.

## Moc

- Low: Moc około 1W podle pasm VHF/UHF.
- Low VERSION DEV: Moc kilku miliwatów dla testów bliśkości.
- Mid: Moc 2-3W podle pasm VHF/UHF.
- High: Maksymalna moc dostarczana przez urządzenie, średnia 5W.

## FAQ

- Czy można blokować K5 tylko w pasmie PMR? Tak, wyświetl menu ukryte, menu nr 48, wartość PMR446 ONLY.
- Czy oprogramowanie jest kompatybilne z modyfikacjami SI4732? Tak, wersja w rozwoju.
- Czy oprogramowanie jest kompatybilne z modyfikacjami EEPROM? Tak, istnieją 2 wersje: 8k i 512k dla zmodyfikowanych K5.
