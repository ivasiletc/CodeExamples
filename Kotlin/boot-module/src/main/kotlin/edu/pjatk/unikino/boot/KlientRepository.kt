package edu.pjatk.unikino.boot

import edu.pjatk.unikino.Klient
import org.springframework.data.repository.CrudRepository

interface KlientRepository: CrudRepository<Klient, Long>