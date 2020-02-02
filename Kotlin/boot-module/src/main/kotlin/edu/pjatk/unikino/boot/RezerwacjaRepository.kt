package edu.pjatk.unikino.boot

import edu.pjatk.unikino.Rezerwacja
import org.springframework.data.repository.CrudRepository

interface RezerwacjaRepository: CrudRepository<Rezerwacja, Long>