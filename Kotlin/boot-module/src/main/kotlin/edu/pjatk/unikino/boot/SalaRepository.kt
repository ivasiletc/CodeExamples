package edu.pjatk.unikino.boot

import edu.pjatk.unikino.Sala
import org.springframework.data.repository.CrudRepository

interface SalaRepository: CrudRepository<Sala, Long>