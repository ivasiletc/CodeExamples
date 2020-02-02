package edu.pjatk.unikino.boot

import edu.pjatk.unikino.Film
import org.springframework.data.repository.CrudRepository

interface FilmRepository: CrudRepository<Film, Long>