package edu.pjatk.unikino

import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id

@Entity
abstract class Osoba
{

    abstract val imie: String
    abstract val nazwisko: String
    
    @Id
    @GeneratedValue
    private val id: Long? = null
    
}