package edu.pjatk.unikino

import java.math.BigDecimal
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id

@Entity
class Moderator(override val pensja: BigDecimal,
                 override val imie: String,
                 override val nazwisko: String) : Pracownik()
{

    @Id
    @GeneratedValue
    private val id: Long? = null
}