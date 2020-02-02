package edu.pjatk.unikino

import edu.pjatk.unikino.boot.FilmRepository
import edu.pjatk.unikino.boot.KinoteatrRepository
import edu.pjatk.unikino.boot.KlientRepository
import edu.pjatk.unikino.boot.RezerwacjaRepository
import edu.pjatk.unikino.boot.SalaRepository
import edu.pjatk.unikino.boot.SeansRepository
import org.springframework.boot.CommandLineRunner
import org.springframework.boot.SpringApplication
import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.context.annotation.Bean
import java.time.LocalDate
import java.time.LocalTime

@SpringBootApplication
class Application
{

    @Bean
    fun init(filmRepository: FilmRepository,
             klientRepository: KlientRepository,
             rezerwacjaRepository: RezerwacjaRepository,
             seansRepository: SeansRepository,
             salaRepository: SalaRepository,
             kinoteatrRepository: KinoteatrRepository) =
        CommandLineRunner {

            val pjatk = Kinoteatr("infinity","123-456-789","Koszykowa 86")
            kinoteatrRepository.save(pjatk)
                
            val sala1 = Sala("Room A", 9, pjatk)
            val sala2 = Sala("Room B", 9, pjatk)
            val sala3 = Sala("Room C", 9, pjatk)
            salaRepository.save(sala1)
            salaRepository.save(sala2)
            salaRepository.save(sala3)        
            
            val film1 = Film("MAS", "Opis filmu MAS", 21, 5.0)
            val film2 = Film("MAD", "Opis filmu MAD", 21, 5.0)
            val film3 = Film("PRI", "Opis filmu PRI", 21, 5.0)
            
            val klient = Klient("534-209-767", "Ivan", "Ivanov")
            klientRepository.save(klient)

            val seans1 = Seans(LocalDate.now(), LocalTime.of(12, 0), LocalTime.of(14, 25), film1, sala1)
            val seans2 = Seans(LocalDate.now(), LocalTime.of(11, 38), LocalTime.of(13, 0), film2, sala1)
            val seans3 = Seans(LocalDate.now(), LocalTime.of(22, 0), LocalTime.of(23, 25), film3, sala3)

            val seans4 = Seans(LocalDate.now(), LocalTime.of(9, 8), LocalTime.of(11, 25), film1, sala2)
            val seans5 = Seans(LocalDate.now(), LocalTime.of(15, 30), LocalTime.of(17, 0), film2, sala2)
            val seans6 = Seans(LocalDate.now(), LocalTime.of(22, 10), LocalTime.of(23, 25), film3, sala2)

            val seans7 = Seans(LocalDate.now(), LocalTime.of(15, 30), LocalTime.of(17, 0), film2, sala2)
            val seans8 = Seans(LocalDate.now(), LocalTime.of(12, 10), LocalTime.of(14, 25), film3, sala1)
            val seans9 = Seans(LocalDate.now(), LocalTime.of(15, 30), LocalTime.of(17, 0), film3, sala2)
            val seans10 = Seans(LocalDate.now(), LocalTime.of(18, 10), LocalTime.of(20, 25), film3, sala3)

            val seans11 = Seans(LocalDate.now(), LocalTime.of(12, 0), LocalTime.of(14, 25), film1, sala3)
                
            filmRepository.save(film1)
            filmRepository.save(film2)
            filmRepository.save(film3)
            
            seansRepository.save(seans1)
            seansRepository.save(seans2)
            seansRepository.save(seans3)
            seansRepository.save(seans4)
            seansRepository.save(seans5)
            seansRepository.save(seans6)
            seansRepository.save(seans7)
            seansRepository.save(seans8)
            seansRepository.save(seans9)
            seansRepository.save(seans10)
            seansRepository.save(seans11)

            val rezerwacja = Rezerwacja(1, 1, "Złożona", "Zwykła", seans1, klient)
            rezerwacjaRepository.save(rezerwacja)
        }
}

fun main(args: Array<String>)
{
    SpringApplication.run(Application::class.java, *args)
}
